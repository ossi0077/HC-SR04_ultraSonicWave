#define trigPin 3
#define echoPin 4

//초음파가 되돌아 오기까지의 시간을 담을 변수 생성
double pulseTime;

void setup()
{
    //각 핀별 사용방법 설정
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    //9600 설정
    Serial.begin(9600);
    delay(2000);
    Serial.println("연결 성공");
    delay(500);
    
    //trig신호 초기화
    digitalWrite(trigPin, LOW);
}

void loop()
{
    //초음파 시작
    digitalWrite(trigPin, HIGH);
    
    //센서 사양대로 10﻿µs동안 초음파 발생
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //초음파 왕복 시간 측정
    pulseTime = pulseIn(echoPin, HIGH);

    //물체와의 거리 계산
    double distance_cm = pulseTime * 17 / 1000;
    double distance_m = distance_cm / 100;

    //센서 사양을 벗어날 시 error 표기
    if ((distance_cm < 400) && (distance_cm > 2))
    {
        Serial.print("거리(cm) = ");
        Serial.println(distance_cm);
        Serial.print("거리(m) = ");
        Serial.println(distance_m);
        Serial.println("--------------------------------------------------");
    }
    else
    {
        Serial.println("제품 사용 가능범위 초과");
    }
    delay(1000);
}
