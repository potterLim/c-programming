#ifndef LAB01_H
#define LAB01_H

extern const int CURRENT_YEAR;

extern int g_age;
extern float g_height_cm;
extern float g_weight_kg;
extern float g_height_m;
extern float g_bmi;
extern float g_health_score;
extern int g_rounded_health_score;

void solve_lab01(void);
const char* get_output_line(const int index);

#endif /* LAB01_H */
