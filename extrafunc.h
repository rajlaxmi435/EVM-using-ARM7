void delay(long int count);

void lcd_cmd(char cmd);

void lcd_string(char str[]);

void lcd_data(char res);

void isr_eint1(void)__irq;

void row_col(void);

void row_res(void);

void eepm_int(void);

void eepm_start(void);

void eepm_config(void);

void eepm_wait(void);

void eepm_data(long int data);

void eepm_clear(void);

char eepm_dtoasc(int dig);

void eepm_stop(void);

void eepm_akn(void);

int pass(void);

void display(int c, int b, int a, int nd);

void winner(int co, int bj, int ap, int ni); 

void eepm_write(char mode, char msb, char lsb, int data);

void eepm_clearall(void);

void eepm_read(char txmode, char rxmode, char msb, char lsb, int data);

void eepm_clear1(void);

char eepm_red(char txmod, char rxmod, char ms, char ls);
