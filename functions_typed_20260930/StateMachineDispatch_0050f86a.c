int __cdecl sub_50F86A(_DWORD *a1)
{
  int v1; // eax
  int v2; // edi

  v1 = a1[4];
  v2 = 0;
  switch ( v1 )
  {
    case 200:
      (*(void (__cdecl **)(_DWORD *))(a1[99] + 4))(a1);
      (*(void (__cdecl **)(_DWORD *))(a1[5] + 8))(a1);
      a1[4] = 201;
      break;
    case 201:
      break;
    case 202:
      return 1;
    default:
      if ( v1 > 202 && (v1 <= 208 || v1 == 210) )
        return (*(int (__cdecl **)(_DWORD *))a1[99])(a1);
      *(_DWORD *)(*a1 + 20) = 18;
      *(_DWORD *)(*a1 + 24) = a1[4];
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      return v2;
  }
  v2 = (*(int (__cdecl **)(_DWORD *))a1[99])(a1);
  if ( v2 == 1 )
  {
    sub_50F6F7((int)a1);
    a1[4] = 202;
  }
  return v2;
}

