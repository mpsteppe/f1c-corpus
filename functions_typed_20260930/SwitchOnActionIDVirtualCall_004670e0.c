int __thiscall sub_4670E0(_DWORD *this)
{
  unsigned int v2; // eax
  int v3; // eax

  v2 = this[205] - 236;
  if ( v2 <= 0xB1 )
  {
    switch ( byte_46713C[v2] )
    {
      case 0:
        v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 14);
        goto LABEL_5;
      case 1:
        v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 11);
LABEL_5:
        if ( v3 )
          ObjectNameComparison(this);
        break;
      case 2:
        return 0;
    }
  }
  return 0;
}

