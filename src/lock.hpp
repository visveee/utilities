unsigned char* hashPassword(unsigned char* password);
int comparePasswordHash(unsigned char* inputPassword);
int savePassword(unsigned char* password);
int setPassword(int display_statusbar, int showlastchar);
int unlockCalc(int display_statusbar, int showlastchar);
int lockCalc(int display_statusbar, int showlastchar, int autopoweroff);