#include <stdint.h>

#define GPIO_BASE 0xc0007000
typedef struct {
        volatile uint32_t DATA_OUT;
		volatile uint32_t DATA_IN;
        volatile uint32_t DIR;
		volatile uint32_t SET;
		volatile uint32_t CLR;
    } gpio_type;
#define GPIO ((gpio_type*)GPIO_BASE)

void wait() {
	for(volatile int i=0;i<10000;i++);
}
int main(void)
{
	GPIO->DIR=0xF;
	while (1) {
		GPIO->DATA_OUT=0xF;
		wait();
		GPIO->DATA_OUT=0x0;
		wait();
	}
}
