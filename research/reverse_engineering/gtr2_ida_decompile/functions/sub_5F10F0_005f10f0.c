int __userpurge sub_5F10F0@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<esi>,
        const char *a5,
        float a6,
        float a7,
        int *a8,
        char a9)
{
  return sub_5F0DD0(
           a1,
           a2,
           a3,
           a5,
           (unsigned __int64)((double)a8[1] * a6 + 0.5),
           (unsigned __int64)((double)a8[2] * a7 + 0.5),
           a8,
           a9,
           a4);
}
