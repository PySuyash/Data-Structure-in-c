// Salary Bonus and Raise int calculateBonus(int salary) - return 10% of salary, void applyRaise (int* salary, float percent) - modifies salary in-place. Simulate for one employee.

#include <stdio.h>

// Returns 10% of salary as bonus (pass-by-value)
int calculateBonus(int salary) {
    return salary * 0.10;
}

// Applies raise to salary in-place (pass-by-reference)
void applyRaise(int *salary, float percent) {
    *salary += (*salary) * (percent / 100.0);
}

int main() {
    int salary = 50000;

    printf("Original salary: %d\n", salary);

    // Calculate bonus
    int bonus = calculateBonus(salary);
    printf("Calculated bonus (10%%): %d\n", bonus);

    // Apply raise
    applyRaise(&salary, 15.0);  // 15% raise
    printf("Salary after 15%% raise: %d\n", salary);

    return 0;
}
