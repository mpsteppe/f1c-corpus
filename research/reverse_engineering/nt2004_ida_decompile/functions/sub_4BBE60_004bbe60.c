void __thiscall sub_4BBE60(float *this, char a2)
{
  double v3; // st7
  float *v4; // eax

  this[4] = dbl_7DA9D0;
  sub_4EDFE0(1);
  sub_42C000(off_5FD348);
  sub_4EEC20(1);
  sub_4EEC50(1);
  sub_4EECE0(1);
  v3 = flt_7D74E0;
  v4 = (float *)off_5FD348;
  *((float *)off_5FD348 + 6008) = flt_7D74E0;
  v4[6007] = v3;
  sub_51C0E0(0);
  this[2] = 0.0;
  if ( a2 )
    *((_BYTE *)this + 1) = 1;
  else
    *((_BYTE *)this + 1) = 0;
  *(_BYTE *)this = 1;
  *((_DWORD *)this + 1) = 1;
  this[3] = sub_4BBF40(this);
}
