// local variable allocation has failed, the output may be wrong!
int sub_434BBC(
        int a1,
        double a2,
        double a3,
        double a4,
        char a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        char a20,
        char a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        char a36,
        char a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        char a52,
        ...)
{
  char *v52; // ecx
  char *v53; // ebx
  char *v54; // esi
  int v55; // edi
  int v56; // esi
  int v58; // [esp+28h] [ebp-1Ch]
  int v59; // [esp+40h] [ebp-4h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h] OVERLAPPED
  double v61; // [esp+48h] [ebp+4h]
  va_list va; // [esp+124h] [ebp+E0h] BYREF

  va_start(va, a52);
  v53 = v52;
  strcpy(&a37, sub_41D840(&byte_91CC38, ":"));
  v54 = v53 + 7338;
  v55 = 3;
  do
  {
    sprintf(v54, off_6F3FD0);
    v54 += 128;
    --v55;
  }
  while ( v55 );
  if ( byte_B72478 )
  {
    a4 = 41.66666666666667;
    v56 = 150;
    strcpy(&a21, sub_41D840(&byte_91CC38, (const char *)&off_6F4840));
  }
  else
  {
    a4 = 44.704;
    v56 = 100;
    strcpy(&a21, sub_41D840(&byte_91CC38, (const char *)&off_6F4830));
  }
  strcpy(&a5, sub_41D840(&byte_91CC38, "ACCELERATION"));
  strcpy(va, sub_41D840(&byte_91CC38, "s"));
  sprintf(v53 + 6954, "%s%s 0-%d %s / ", &a5, &a37, v56, &a21);
  sub_434730();
  strcpy(&a5, sub_41D840(&byte_91CC38, "TOP SPEED"));
  sprintf(v53 + 7082, "%s%s", &a5, &a37);
  *(double *)&retaddr = 0.0;
  sub_434730();
  if ( byte_B72478 )
    v58 = sub_431910(*(double *)&v59 * 3.6);
  else
    v58 = sub_431910(*(double *)&v59 * 2.236936292054402);
  sprintf(v53 + 7466, "%d %s", v58, &a20);
  v61 = sub_434480((int)v53, 75.0);
  strcpy((char *)&a4 + 4, sub_41D840(&byte_91CC38, "MAXIMUM CORNERING FORCE"));
  strcpy(&a52, sub_41D840(&byte_91CC38, "g"));
  sprintf(v53 + 7210, "%s%s", (const char *)&a4 + 4, &a36);
  return sprintf(v53 + 7594, "%.2f %s", v61 * 0.1019367991845056, &a52);
}
