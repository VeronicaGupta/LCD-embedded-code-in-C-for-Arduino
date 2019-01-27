char x, y;
int r = 12, e = 11;
char m[4] = {0x10, 0x20, 0x40, 0x80};
int a[4] = {5, 4, 3, 2};
void lcd_init(void);
void enable(void);
void data(char x);
void comm(char x);
void setup() {
    // put your setup code here, to run once:
     pinMode(r, OUTPUT);
     pinMode(e, OUTPUT);
    for (int i = 2; i < 6; i++)
      pinMode(i, OUTPUT);

lcd_init();

}
int j;
void loop() {
    // put your main code here, to run repeatedly:
  delay(300);
  data('a');
}

void enable(void)
{
    digitalWrite(r, 0);
    digitalWrite(e, 1);
    delay(10);
    digitalWrite(e, 0);
}

void enable1(void)
{
    digitalWrite(r, 1);
    digitalWrite(e, 1);
    delay(10);
    digitalWrite(e, 0);
}
void comm(char x)
{
    int i;
    char y;
   for (i = 0; i <= 3; i++)
 {
      y = x & m[i];
      if (y)
          digitalWrite(a[i], 1);
      else
            digitalWrite(a[i], 0);
 }
    enable();

     for (i = 0; i <= 3; i++)
 {
      y = (x << 4) & m[i];
      if (y) 
          digitalWrite(a[i], 1);
      else
          digitalWrite(a[i], 0);
 }
    enable();
}

void data(char x)
{
   int i;
   char y;
   for (i = 0; i <= 3; i++)
 {
      y = x & m[i];
      if (y)
          digitalWrite(a[i], 1);
      else
            digitalWrite(a[i], 0);
 }
    enable1();

     for (i = 0; i <= 3; i++)
 {
      y = (x << 4) & m[i];
      if (y) 
          digitalWrite(a[i], 1);
      else
          digitalWrite(a[i], 0);
 }
    enable1();
 
}
void lcd_init(void) {
    comm(0x02);
    comm(0x28);
    comm(0x06);
    comm(0x0E);
    comm(0x01);
    comm(0x80);  
}

