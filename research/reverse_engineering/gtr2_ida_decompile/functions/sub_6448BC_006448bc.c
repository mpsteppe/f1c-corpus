int __userpurge sub_6448BC@<eax>(int a1@<eax>, LPCWCH lpWideCharStr, int a3, int a4, int a5, int a6)
{
  int v7; // esi
  int v8; // eax
  int v9; // esi
  _BYTE v11[84]; // [esp+4h] [ebp-DCh] BYREF
  _BYTE v12[84]; // [esp+58h] [ebp-88h] BYREF
  _BYTE v13[12]; // [esp+ACh] [ebp-34h] BYREF
  int v14; // [esp+B8h] [ebp-28h]
  _BYTE v15[20]; // [esp+CCh] [ebp-14h] BYREF

  sub_6464A7(v12);
  sub_64E466(v15);
  if ( lpWideCharStr && a1 )
  {
    v8 = sub_64E610(v11, a1, a4, a5, 0, 1);
    if ( v8 < 0 || (v8 = sub_64653C(v11), v8 < 0) || (v8 = sub_64A702(lpWideCharStr, a3, a6), v8 < 0) )
    {
      v7 = v8;
    }
    else
    {
      (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)a1 + 48))(a1, v13);
      if ( v14
        || ((*(void (__stdcall **)(int, LPCWCH *))(*(_DWORD *)a1 + 12))(a1, &lpWideCharStr),
            v9 = (*(int (__stdcall **)(LPCWCH))(*(_DWORD *)lpWideCharStr + 12))(lpWideCharStr),
            (*(void (__stdcall **)(LPCWCH))(*(_DWORD *)lpWideCharStr + 8))(lpWideCharStr),
            !v9) )
      {
        v7 = 0;
      }
      else
      {
        v7 = -2005530520;
      }
    }
  }
  else
  {
    v7 = -2005530516;
  }
  sub_64E60B(v15);
  sub_6464C0(v12);
  return v7;
}
