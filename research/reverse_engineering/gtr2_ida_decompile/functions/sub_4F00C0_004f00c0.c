void __thiscall sub_4F00C0(int this, char a2)
{
  int v3; // esi
  int v4; // eax
  int v5; // ecx
  _DWORD v6[3]; // [esp+4h] [ebp-18h] BYREF
  _DWORD v7[3]; // [esp+10h] [ebp-Ch] BYREF

  if ( flt_B70A44 != 0.0 )
  {
    if ( a2
      && !*(_BYTE *)(this + 440)
      && !byte_B6F118
      && *(_DWORD *)dword_B72314 != 7
      && *(_DWORD *)dword_B72314 != 8
      && *(_DWORD *)(this + 424) == 2139095039 )
    {
      v3 = 0;
      while ( 1 )
      {
        v4 = *(_DWORD *)(this + 4 * v3);
        if ( v4 )
        {
          if ( (*(int (**)(void))(*(_DWORD *)v4 + 28))() != 2 )
            break;
        }
        if ( ++v3 >= 81 )
        {
          v5 = *(_DWORD *)(this + 120);
          if ( v5 )
          {
            memset(v7, 0, sizeof(v7));
            memset(v6, 0, sizeof(v6));
            (*(void (__thiscall **)(int, int, _DWORD *, _DWORD *, _DWORD, int, _DWORD))(*(_DWORD *)v5 + 4))(
              v5,
              2,
              v7,
              v6,
              LODWORD(flt_B70A44),
              1065353216,
              0);
          }
          break;
        }
      }
    }
    *(_BYTE *)(this + 440) = a2;
  }
}
