char __thiscall sub_565F40(int this)
{
  int v2; // ecx
  char v3; // bl
  int v4; // edi
  int v5; // esi
  int v6; // esi
  bool v7; // zf

  v2 = *(_DWORD *)(this + 32);
  v3 = 0;
  v4 = dword_757C10;
  if ( v2 > 0 && !(v2 % 6) || v2 == dword_757C10 )
    v3 = 1;
  v5 = *(_DWORD *)(dword_91E084 + 19324);
  if ( sub_565F00() == v5 && v5 != v4 )
  {
    v3 = 1;
    if ( *(_BYTE *)(this + 40) == 1 )
    {
      v6 = v5 + 1;
      v7 = v6 == v4;
      if ( v6 < v4 )
      {
        do
        {
          if ( !dword_925054[5654 * sub_5511F0(dword_FADD40, v6 - 1)] )
            break;
          ++v6;
        }
        while ( v6 < dword_757C10 );
        v7 = v6 == dword_757C10;
      }
      if ( v7 )
        v3 = 0;
    }
    *(_BYTE *)(this + 40) = 1;
  }
  return v3;
}
