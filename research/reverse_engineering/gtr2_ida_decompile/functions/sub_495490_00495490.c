int sub_495490()
{
  double v1; // st7
  int v2; // [esp+4h] [ebp-1Ch] BYREF
  int v3; // [esp+8h] [ebp-18h] BYREF
  int v4; // [esp+Ch] [ebp-14h] BYREF
  char Buffer[16]; // [esp+10h] [ebp-10h] BYREF

  if ( !(unsigned __int8)sub_54B750(&unk_BE27B0) )
    return sub_4CE020(WindowName);
  v1 = sub_54B370(&unk_BE27B0);
  *(float *)&v2 = v1;
  if ( v1 <= 0.0 )
  {
    if ( *(float *)&v2 <= 0.0 )
      strcpy(Buffer, "--:--:--");
    return sub_4CE020(Buffer);
  }
  else
  {
    sub_4E42F0(*(float *)&v2, (int)&v4, (int)&v3, (int)&v2);
    sprintf(Buffer, "%.2d:%.2d:%.2d", v4, v3, (unsigned int)(unsigned __int64)*(float *)&v2);
    return sub_4CE020(Buffer);
  }
}
