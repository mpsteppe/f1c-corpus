int __thiscall sub_694F9B(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // esi

  v3 = (_DWORD *)a2;
  if ( a2 )
  {
    switch ( *(_DWORD *)(a2 + 4) )
    {
      case 1:
        do
        {
          if ( v3[1] != 1 )
            break;
          sub_694F9B(v3[2], a3);
          v3 = (_DWORD *)v3[3];
        }
        while ( v3 );
        if ( v3 )
          sub_694F9B(v3, a3);
        break;
      case 6:
        sub_694F9B(*(_DWORD *)(a2 + 24), a3);
        break;
      case 8:
        sub_694F9B(*(_DWORD *)(a2 + 16), a3);
        break;
      case 9:
        if ( a3 )
          *(_BYTE *)(a2 + 33) |= 2u;
        else
          *(_BYTE *)(a2 + 33) &= ~2u;
        break;
      case 0xB:
        sub_694F9B(*(_DWORD *)(a2 + 32), a3);
        break;
      default:
        sub_694C3A(this, 0, 0, "internal error: unknown node");
        break;
    }
  }
  return 0;
}
