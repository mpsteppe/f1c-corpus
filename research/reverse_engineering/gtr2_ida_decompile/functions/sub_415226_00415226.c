int __stdcall sub_415226(float a1, const char *a2)
{
  const char *v2; // esi
  double v3; // st7
  char Buffer[128]; // [esp+4h] [ebp-80h] BYREF
  float v6; // [esp+88h] [ebp+4h]

  v2 = a2;
  if ( !a2 )
    v2 = WindowName;
  v3 = a1 + 1.0;
  v6 = v3;
  sprintf(
    Buffer,
    "%s%02d:%02d",
    v2,
    (unsigned int)(unsigned __int64)(0.016666668 * (v3 + 1.0)),
    (unsigned int)(unsigned __int64)(v3 + 1.0 - (double)(int)(unsigned __int64)(0.016666668 * (v3 + 1.0)) * 60.0));
  sub_472920(Buffer, 0);
  sprintf(
    Buffer,
    "%s%02d:%02d",
    v2,
    (unsigned int)(unsigned __int64)(v6 * 0.016666668),
    (unsigned int)(unsigned __int64)(v6 - (double)(int)(unsigned __int64)(v6 * 0.016666668) * 60.0));
  return sub_4730C0(Buffer, 3, &byte_1020304, 1084227584);
}
