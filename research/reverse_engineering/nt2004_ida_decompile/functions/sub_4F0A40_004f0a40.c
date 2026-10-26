int __thiscall sub_4F0A40(_DWORD *this)
{
  double v2; // st7
  int v3; // esi
  _DWORD *v4; // edi
  int v5; // ecx
  _DWORD v7[3]; // [esp+10h] [ebp-Ch] BYREF

  if ( dword_75CBB0 != 8 )
  {
    if ( dword_75CBB0 )
    {
      v2 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
      if ( v2 < flt_7D6BA4 / 1.0 * 0.15000001 )
      {
        v3 = 0;
        v4 = this + 7;
        do
        {
          if ( *v4 && (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v4 + 28))(*v4) != 2 )
            break;
          ++v3;
          ++v4;
        }
        while ( v3 < 3 );
        if ( v3 == 3 )
        {
          v5 = this[rand() % 3 + 7];
          if ( v5 )
          {
            memset(v7, 0, sizeof(v7));
            (*(void (__thiscall **)(int, _DWORD, _DWORD *, _DWORD *, int, int, int))(*(_DWORD *)v5 + 4))(
              v5,
              0,
              this + 2,
              v7,
              dword_76782C,
              1065353216,
              1);
          }
        }
      }
    }
  }
  return 0;
}
