char __stdcall sub_4DDDB0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  char result; // al
  int v7[8]; // [esp+0h] [ebp-20h] BYREF

  *(float *)v7 = (float)a1;
  v7[2] = 0;
  v7[5] = 0;
  *(float *)&v7[1] = (float)a2;
  *(float *)&v7[3] = (float)a3;
  *(float *)&v7[4] = (float)a4;
  result = sub_4DDA50(a6, (float *)v7);
  if ( result )
    return sub_5F5470((int)v7, a5, (void *)1);
  return result;
}
