// f1c  0x004dad80  size=128
char __thiscall sub_4DAD80(int this)
{
  char v2; // bl
  char v3; // al
  int v4; // edi
  int v5; // esi
  int v6; // esi
  bool v7; // zf

  v2 = 0;
  v3 = sub_4DAE80();
  v4 = dword_5C329C;
  if ( v3 || *(_DWORD *)(this + 32) == dword_5C329C )
    v2 = 1;
  v5 = *(_DWORD *)(dword_7C54E8 + 16480);
  if ( sub_4DA990((_DWORD *)this) == v5 && v5 != v4 )
  {
    v2 = 1;
    if ( *(_BYTE *)(this + 40) == 1 )
    {
      v6 = v5 + 1;
      v7 = v6 == v4;
      if ( v6 < v4 )
      {
        do
        {
          if ( !dword_5F073C[4656 * sub_4D1B50((unsigned __int8 *)dword_8ACEE0, v6 - 1)] )
            break;
          ++v6;
        }
        while ( v6 < dword_5C329C );
        v7 = v6 == dword_5C329C;
      }
      if ( v7 )
        v2 = 0;
    }
    *(_BYTE *)(this + 40) = 1;
  }
  return v2;
}
