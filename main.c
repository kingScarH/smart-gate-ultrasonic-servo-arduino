/*
 * ------------------------------------------------------------
 * Project   : Smart Gate System using Ultrasonic Sensor and Servo
 * Platform  : Arduino UNO
 * Author    : kingScarH (S. Ray)
 * Date      : October 2025
 * ------------------------------------------------------------
 * Description:
 * This program controls a servo-based gate using an ultrasonic sensor.
 * When a car is detected within a certain range, the gate opens automatically.
 * The system includes visual (LED) and audio (buzzer) indicators.
 * ------------------------------------------------------------
 */

#include <Servo.h>

/* ------------------- Pin Definitions ------------------- */
#define TRIG_PIN       (2)
#define ECHO_PIN       (3)
#define SERVO_PIN      (9)
#define GREEN_LED_PIN  (5)
#define RED_LED_PIN    (6)
#define BUZZER_PIN     (7)

/* ------------------- Global Variables ------------------- */
static Servo gate_servo;
static long echo_duration = 0;
static int distance_cm = 0;
static const int GATE_OPEN_ANGLE = 90;
static const int GATE_CLOSE_ANGLE = 180;
static bool gate_is_open = false;

/* ------------------- Function Prototypes ------------------- */
static int get_distance(void);
static void open_gate(void);
static void close_gate(void);
static void beep_buzzer(int times, int delay_ms);

/* ------------------- Setup Function ------------------- */
void setup(void)
{
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    gate_servo.attach(SERVO_PIN);
    gate_servo.write(GATE_CLOSE_ANGLE);

    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("System Ready - Waiting for vehicle detection...");
}

/* ------------------- Main Loop ------------------- */
void loop(void)
{
    distance_cm = get_distance();

    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");

    if ((distance_cm > 0) && (distance_cm < 20) && (gate_is_open == false))
    {
        Serial.println("Vehicle detected. Opening gate...");
        open_gate();
    }
    else if (((distance_cm >= 20) || (distance_cm == 0)) && (gate_is_open == true))
    {
        Serial.println("No vehicle detected. Closing gate...");
        close_gate();
    }

    delay(300);
}

/* ------------------- Distance Measurement ------------------- */
static int get_distance(void)
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    echo_duration = pulseIn(ECHO_PIN, HIGH, 30000UL);  /* Timeout 30ms */
    int distance = (int)((echo_duration * 0.034F) / 2.0F);

    return distance;
}

/* ------------------- Gate Control: Open ------------------- */
static void open_gate(void)
{
    gate_servo.write(GATE_OPEN_ANGLE);

    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    beep_buzzer(2, 100);
    gate_is_open = true;

    delay(3000);
}

/* ------------------- Gate Control: Close ------------------- */
static void close_gate(void)
{
    gate_servo.write(GATE_CLOSE_ANGLE);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    beep_buzzer(3, 80);
    gate_is_open = false;
}

/* ------------------- Buzzer Beep Function ------------------- */
static void beep_buzzer(int times, int delay_ms)
{
    int i;
    for (i = 0; i < times; i++)
    {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(delay_ms);
        digitalWrite(BUZZER_PIN, LOW);
        delay(delay_ms);
    }
}
