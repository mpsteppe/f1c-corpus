// f1c  0x004a4710  size=199
int __thiscall sub_4A4710(_BYTE *this, int a2)
{
  int result; // eax
  int *v4; // esi
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  double v8; // st7
  double v9; // st7
  float v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]

  result = 0;
  v10 = 99999.0;
  v11 = 0;
  if ( *(_DWORD *)&this[4 * a2] )
  {
    v4 = dword_7C54F0;
    v5 = this - (_BYTE *)dword_7C54F0;
    do
    {
      v6 = *(int *)((char *)v4 + v5);
      if ( v6 )
      {
        v7 = sub_42ADD0(v6);
        v8 = sub_426CC0((_DWORD *)*(_DWORD *)&this[4 * a2], v7);
        if ( v8 < v10 && v8 > 0.0 )
        {
          v10 = v8;
          v11 = *(int *)((char *)v4 + v5);
        }
      }
      else if ( *(_DWORD *)(*v4 + 13000) != 1 )
      {
        v9 = sub_426CC0((_DWORD *)*(_DWORD *)&this[4 * a2], *(_DWORD *)(*v4 + 15016));
        if ( v9 < v10 && v9 > 0.0 )
        {
          v10 = v9;
          v11 = *v4;
        }
      }
      ++v4;
    }
    while ( (int)v4 < (int)&byte_7C5690 );
    return v11;
  }
  return result;
}
