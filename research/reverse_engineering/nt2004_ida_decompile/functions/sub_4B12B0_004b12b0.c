char __thiscall sub_4B12B0(_DWORD *this, int a2)
{
  int v2; // eax
  char *v3; // ecx
  char *v4; // ecx
  int v5; // esi

  v2 = *this - 1;
  switch ( *this )
  {
    case 1:
      v3 = (char *)this[1];
      if ( !v3 )
        v3 = &byte_629120;
      LOBYTE(v2) = sub_4AD720(*(_DWORD **)(a2 + 48), v3, 1);
      break;
    case 4:
      LOBYTE(v2) = sub_4AD840(*(_DWORD **)(a2 + 48));
      break;
    case 5:
      dword_608F60 = -1;
      break;
    case 6:
      v4 = (char *)this[3];
      if ( !v4 )
        v4 = &byte_629120;
      v2 = sub_4AD520(*(void **)(a2 + 48), v4);
      v5 = v2;
      if ( v2 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 132))(v2);
        sub_4AD850(*(_DWORD **)(a2 + 48), v5);
        LOBYTE(v2) = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 136))(v5);
      }
      break;
    case 7:
      LOBYTE(v2) = sub_4AD760(*(_DWORD **)(a2 + 48));
      break;
    default:
      return v2;
  }
  return v2;
}
