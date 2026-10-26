char __usercall sub_408890@<al>(_DWORD *a1@<ecx>, int a2@<ebx>)
{
  char result; // al
  int v4; // eax
  int v5; // eax
  _DWORD v6[3]; // [esp+38h] [ebp-18h] BYREF
  int v7; // [esp+4Ch] [ebp-4h]

  result = dword_B72314[0];
  if ( *(_DWORD *)dword_B72314 != 7 && *(_DWORD *)dword_B72314 != 8 )
  {
    v4 = dword_BE1CD8 + 396 * dword_BE1CD4;
    if ( v4 )
    {
      v7 = 1;
      sub_615860(v4 + 4);
      sub_408500(WindowName);
      v5 = strlen(WindowName);
      if ( v5 > 0 && WindowName[v5 - 1] == 92 )
        WindowName[v5 - 1] = 0;
      sub_615860(396 * dword_BE1CD4 + dword_BE1CD8 + 260);
      sub_615A50(".ani");
      sub_407B10();
      LOBYTE(v7) = 2;
      sub_5D9420(v6, WindowName, 0, a2);
      sub_4080A0();
      sub_5D9900(v6, WindowName, 0);
      LOBYTE(v7) = 1;
      sub_407AE0();
      v7 = -1;
    }
    return sub_408730(a1, 0.0);
  }
  return result;
}
