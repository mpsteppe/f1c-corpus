_DWORD *__stdcall sub_54B0BD(_DWORD *a1, _DWORD *a2, int a3, int a4, float a5, float a6)
{
  float v7; // [esp+4h] [ebp-28h]
  int v8[4]; // [esp+Ch] [ebp-20h] BYREF
  int v9[4]; // [esp+1Ch] [ebp-10h] BYREF
  float v10; // [esp+44h] [ebp+18h]

  v10 = a5 + a6;
  if ( sub_548E48(v10, 0.0) )
  {
    if ( a1 != a2 )
    {
      *a1 = *a2;
      a1[1] = a2[1];
      a1[2] = a2[2];
      a1[3] = a2[3];
    }
  }
  else
  {
    sub_54AF13((int)v8, (int)a2, a3, v10);
    sub_54AF13((int)v9, (int)a2, a4, v10);
    v7 = a6 / v10;
    sub_54AF13((int)a1, (int)v8, (int)v9, v7);
  }
  return a1;
}
