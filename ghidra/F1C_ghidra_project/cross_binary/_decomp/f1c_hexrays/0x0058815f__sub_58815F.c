// f1c  0x0058815f  size=82
int sub_58815F(_BYTE *a1, int a2, ...)
{
  int v2; // eax
  bool v3; // sf
  int v4; // esi
  _BYTE *v6; // [esp+4h] [ebp-20h] BYREF
  int v7; // [esp+8h] [ebp-1Ch]
  _BYTE *v8; // [esp+Ch] [ebp-18h]
  int v9; // [esp+10h] [ebp-14h]
  va_list va; // [esp+34h] [ebp+10h] BYREF

  va_start(va, a2);
  v8 = a1;
  v6 = a1;
  v9 = 66;
  v7 = 0x7FFFFFFF;
  v2 = sub_58D04D(&v6, a2, va);
  v3 = --v7 < 0;
  v4 = v2;
  if ( v3 )
    sub_58CF35(0, &v6);
  else
    *v6 = 0;
  return v4;
}
