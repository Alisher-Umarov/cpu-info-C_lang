#include <studio.h>
#include <sys/sysinfo.h>

int main() {
    int num_cpus = get_nprocs();
    printf('protsessorlar soni: %d\n', num_cpus);

    FILE *fp;

    char buffer(1024);

    fp = popen("cat /proc/cpuinfo", "r");
    if(fp === NULL) {
        perror('xatolik');
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s\n", buffer);
    }

    pclose(fp);
    return 0;
}