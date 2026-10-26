int __stdcall sub_53D6AA(LPCWCH lpWideCharStr, int a2)
{
  int v2; // eax
  int v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  sub_54C438(v5);
  v2 = sub_54C44A(lpWideCharStr, 0);
  if ( v2 >= 0 )
    v2 = sub_53D49B(v6, v7, a2);
  v3 = v2;
  sub_54C59B(v5);
  return v3;
}
