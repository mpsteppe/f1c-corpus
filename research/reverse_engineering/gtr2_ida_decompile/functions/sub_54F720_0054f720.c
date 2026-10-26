int __thiscall sub_54F720(int *this, float a2)
{
  float *v3; // eax
  double v4; // st7
  int result; // eax
  int v6; // ebp
  int v7; // ebx
  int v8; // esi
  int v9; // ecx
  int v10; // esi
  double v11; // st7
  double v12; // st7
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  float v16; // [esp+8h] [ebp-18h] BYREF
  float v17; // [esp+Ch] [ebp-14h] BYREF
  float v18; // [esp+10h] [ebp-10h] BYREF
  float v19; // [esp+14h] [ebp-Ch]
  float v20; // [esp+18h] [ebp-8h]
  float v21; // [esp+1Ch] [ebp-4h]

  v3 = (float *)sub_40DCE0(&dword_91BF20);
  if ( v3 )
  {
    v16 = -v3[3];
    v17 = -v3[4];
    v4 = -v3[5];
    v19 = v16;
    v18 = v4;
    v20 = v17;
    v21 = v18;
  }
  else
  {
    v19 = 0.0;
    v20 = 0.0;
    v21 = 0.0;
  }
  result = *this;
  v6 = 0;
  if ( *this > 0 )
  {
    v7 = 0;
    do
    {
      v8 = this[1];
      v9 = *(_DWORD *)(v8 + v7 + 140);
      v10 = v7 + v8;
      if ( v9 )
      {
        sub_5DA7A0(&v16, &v17, &v18);
        v16 = v16 - v19;
        v17 = v17 - v20;
        v11 = v18 - v21;
        v18 = v11;
        if ( v11 * v18 + v17 * v17 + v16 * v16 < 1024.0 )
        {
          v12 = a2 + *(float *)(v10 + 776);
          *(float *)(v10 + 776) = v12;
          if ( !(v14 | v15) )
            *(float *)(v10 + 776) = v12 - *(float *)(v10 + 772);
          pfnAPC(*(_DWORD *)(v10 + 776));
        }
      }
      result = *this;
      ++v6;
      v7 += 780;
    }
    while ( v6 < *this );
  }
  return result;
}
