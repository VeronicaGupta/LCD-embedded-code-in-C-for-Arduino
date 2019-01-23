
//lcd(3,2,4,5,6,7)- RS / E / D4 / D5 / D6 /D7
int r=3;
int e=2;
char m[4]={0x10,0x20,0x40,0x80};
int a[4]=(4,5,6,7);

void enable(void)
{
  digitalWrite(r,0);
  digitalWrite(e,1);
  delay(10);
  digitalWrite(e,0);
}

void enable1(void)
{
  digitalWrite(r,1);
  digitalWrite(e,1);
  delay(10);
  digitalWrite(e,0);
}

void comm(char x)
{
  int i;
  char y;
  
  for(int i=0;i<4;i++)
  {
  y= x & m[i];
  
  if(y)
  digitalWrite(a[i],1);
  else 
  digitalWrite(a[i],0);
  
  enable();
  }

  for(int i=0;i<4;i++)
  {
  y= (x<<4) & m[i];
  
  if(y)
  digitalWrite(a[i],1);
  else 
  digitalWrite(a[i],0);
  
  enable();
  
  }
}

void data(char x)
{
  int i;
  char y;
  
  for(i=0;i<4;i++)
  {
  y=x & m[i];
  
  if(y)
  digitalWrite(a[i],1);
  else 
  digitalWrite(a[i],0);
  
  enable1();
  }
  
  for(int i=0;i<4;i++)
  {
  y= (x<<4) & m[i];
  
  if(y)
  digitalWrite(a[i],1);
  else 
  digitalWrite(a[i],0);
  
  enable1(); 
  }
}

void init(void)
{
  comm(0x02);
  comm(0x28);
  comm(0x06);
  comm(0x0E);
  comm(0x01);
  comm(0x80);
}


void setup(void)
{
  // put your setup code here, to run once:
for(int i=2;i<8;i++)
  pinMode(i,OUTPUT);
  
init(); 
}
void loop(void)
{
  // put your main code here, to run repeatedly:
data('a');
delay(500);
}
