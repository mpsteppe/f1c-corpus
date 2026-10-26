int __thiscall sub_405080(float *this)
{
  int v2; // esi
  int result; // eax
  int i; // ecx
  float v5[3]; // [esp+8h] [ebp-Ch] BYREF

  v2 = 0;
  this[105] = 0.0;
  result = sub_42DBC0(&unk_62BF64);
  if ( (_BYTE)result )
  {
    result = *(_DWORD *)((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC + 0x62B0 : 25264);
    if ( result >= 0 )
    {
      result = sub_4040B0(&flt_628F60, v5, 0, result + dword_628FA8, 0.0, 0);
      if ( result )
      {
        for ( i = *(_DWORD *)(result + 292); i; i = *(_DWORD *)(i + 292) )
        {
          if ( !*(_DWORD *)(i + 328) )
            break;
          result = v2++;
          if ( result > 700 )
            return result;
          result = i;
        }
        this[105] = *(float *)(*(_DWORD *)(result + 292) + 116) - 20.0;
      }
    }
  }
  return result;
}
