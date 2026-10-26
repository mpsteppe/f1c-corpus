char __thiscall sub_4E3B60(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  const CHAR *v4; // ecx
  const CHAR *v5; // ecx
  int v6; // esi

  v3 = *this - 1;
  switch ( *this )
  {
    case 1:
      v4 = (const CHAR *)this[1];
      if ( !v4 )
        v4 = WindowName;
      LOBYTE(v3) = sub_4E1810(*(_DWORD **)(a2 + 48), (int)v4, a3);
      break;
    case 4:
      LOBYTE(v3) = sub_4DF020(*(_DWORD **)(a2 + 48));
      break;
    case 5:
      dword_75B17C = -1;
      break;
    case 6:
      v5 = (const CHAR *)this[3];
      if ( !v5 )
        v5 = WindowName;
      v3 = sub_4DEF00(*(void **)(a2 + 48), (int)v5);
      v6 = v3;
      if ( v3 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 132))(v3);
        sub_4DF030(*(_DWORD **)(a2 + 48), v6);
        LOBYTE(v3) = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 136))(v6);
      }
      break;
    case 7:
      LOBYTE(v3) = sub_4E1850(*(void **)(a2 + 48), a3);
      break;
    default:
      return v3;
  }
  return v3;
}
