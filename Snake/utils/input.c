#define GPIO_D_BASE     0x40020C00
#define GPIO_D_MODER    ((unsigned long *) (GPIO_D_BASE))
#define GPIO_D_OTYPER   ((unsigned short *) (GPIO_D_BASE + 4))
#define GPIO_D_PUPDR    ((unsigned long *) (GPIO_D_BASE + 0xC))
#define GPIO_D_ODR      ((unsigned short *) (GPIO_D_BASE + 0x14))
#define GPIO_D_ODR_HIGH ((unsigned char *) (GPIO_D_BASE + 0x15))
#define GPIO_D_IDR_HIGH ((unsigned char *) (GPIO_D_BASE + 0x11))

void input_init(void)
{
  /* starta klockor port D och E */
//   *((unsigned long *) 0x40023830) = 0x18;

  *GPIO_D_MODER = 0x55005555;
  *GPIO_D_OTYPER &= 0xFFFF00FF;
  *GPIO_D_OTYPER |= 0x0000;
  *GPIO_D_PUPDR &= 0x0000FFFF;
  *GPIO_D_PUPDR |= 0x00AA0000;
}

void kbdActivate(unsigned int row)
{
	switch (row) {
    case 1:
      *GPIO_D_ODR_HIGH = 0x10;
      break;
    case 2:
      *GPIO_D_ODR_HIGH = 0x20;
      break;
    case 3:
      *GPIO_D_ODR_HIGH = 0x40;
      break;
    case 4:
      *GPIO_D_ODR_HIGH = 0x80;
      break;
    default:
      *GPIO_D_ODR_HIGH = 0;
      break;
	}
}

int kbdGetCol( void )
{
  unsigned char c;
  c = * GPIO_D_IDR_HIGH;

  if (c & 8) 
    return 4;
  if (c & 4)
    return 3;
  if (c & 2)
    return 2;
  if (c & 1)
    return 1;

  return 0;
}

unsigned char keyb(void)
{
  char key[] = {1, 2, 3, 0xA, 4, 5, 6, 0xB, 7, 8, 9, 0xC, 0xE, 0, 0xF, 0xD};
  int row, col;
  for (row = 1; row <= 4; row++)
  {
      kbdActivate(row);
      if (col = kbdGetCol())
      {
        kbdActivate(0);
        return key[4 * (row - 1) + (col - 1)];
      }
  }
  kbdActivate(0);
  return 0xFF;
}