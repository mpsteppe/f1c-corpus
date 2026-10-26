int sub_58969D(_BYTE *a1, int a2, const char *a3, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _BYTE *v7; // [esp+4h] [ebp-20h] BYREF
  int v8; // [esp+8h] [ebp-1Ch]
  _BYTE *v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  va_list va; // [esp+38h] [ebp+14h] BYREF

  va_start(va, a3);
  v9 = a1;
  v7 = a1;
  v10 = 66;
  v8 = a2;
  v3 = sub_58D04D(&v7, a3, va);
  v4 = --v8 < 0;
  v5 = v3;
  if ( v4 )
    sub_58CF35(0, &v7);
  else
    *v7 = 0;
  return v5;
}
