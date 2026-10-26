_onexit_t __cdecl _onexit(_onexit_t Func)
{
  unsigned int v1; // eax
  _onexit_t *v2; // ecx
  int v3; // eax
  char *v4; // eax
  int (__cdecl *v5)(); // esi
  int v6; // ecx

  _lockexit();
  v1 = sub_5C2C6C(dword_801514);
  v2 = (_onexit_t *)dword_801510;
  if ( v1 >= dword_801510 - (int)dword_801514 + 4 )
    goto LABEL_5;
  v3 = sub_5C2C6C(dword_801514);
  v4 = (char *)sub_5C293D((LPVOID)dword_801514, v3 + 16);
  if ( v4 )
  {
    v6 = dword_801510 - (_DWORD)dword_801514;
    dword_801514 = v4;
    v2 = (_onexit_t *)&v4[4 * (v6 >> 2)];
    dword_801510 = (int)v2;
LABEL_5:
    *v2 = Func;
    dword_801510 += 4;
    v5 = Func;
    goto LABEL_6;
  }
  v5 = 0;
LABEL_6:
  _unlockexit();
  return v5;
}
