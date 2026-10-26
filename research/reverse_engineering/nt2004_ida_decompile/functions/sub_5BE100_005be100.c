_DWORD *__fastcall sub_5BE100(int a1, int a2, int a3)
{
  _DWORD *v5; // esi

  v5 = malloc(0x18u);
  if ( !a2 )
    a2 = 8;
  *v5 = 0;
  v5[1] = a2;
  v5[2] = a1;
  v5[3] = a2;
  v5[4] = a3;
  v5[5] = malloc(a2 * a1);
  return v5;
}
