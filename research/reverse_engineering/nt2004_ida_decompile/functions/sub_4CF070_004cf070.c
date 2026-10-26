char __thiscall sub_4CF070(int this, char *String)
{
  double v3; // st7
  char *v4; // edx
  bool v5; // c0
  bool v6; // c3

  if ( *(float *)&String == 0.0 || !strlen(String) )
    return 0;
  sub_4BC060(String, (float *)&String);
  v3 = *(float *)(this + 28);
  v4 = *(char **)(this + 32);
  *(float *)(this + 20) = *(float *)&String;
  v5 = v3 < *(float *)(this + 20);
  v6 = v3 == *(float *)(this + 20);
  String = v4;
  if ( v5 || v6 )
  {
    if ( *(float *)(this + 20) > (double)*(float *)&String )
      *(float *)(this + 20) = *(float *)&String;
    return 1;
  }
  else
  {
    *(float *)(this + 20) = v3;
    return 1;
  }
}
