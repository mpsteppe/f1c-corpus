int __thiscall sub_4FB0E0(int *this, int a2)
{
  int result; // eax
  int *v4; // esi
  int *v5; // edi
  int v6; // eax
  double v7; // st7
  double v8; // st7
  float v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  result = 0;
  v9 = 99999.0;
  v10 = 0;
  if ( this[a2] )
  {
    v4 = &dword_9248F4;
    v5 = this;
    do
    {
      if ( *v5 )
      {
        v6 = sub_422780(*v5);
        v7 = sub_41FB10((_DWORD *)this[a2], v6);
        if ( v7 < v9 && v7 > 0.0 )
        {
          v9 = v7;
          v10 = *v5;
        }
      }
      else if ( *(v4 - 668) != 1 )
      {
        v8 = sub_41FB10((_DWORD *)this[a2], *v4);
        if ( v8 < v9 && v8 > 0.0 )
        {
          v9 = v8;
          v10 = (int)(v4 - 4373);
        }
      }
      v4 += 5654;
      ++v5;
    }
    while ( (int)v4 < (int)dword_B62CB4 );
    return v10;
  }
  return result;
}
