int __thiscall sub_409970(_DWORD *this)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-10h]
  float v3; // [esp+4h] [ebp-Ch]

  if ( this[2] )
  {
    v3 = flt_7CF6C8 * 0.01745433;
    *(float *)&v2 = flt_7CF6A4 * 0.01745433;
    sub_542050(v2, v3, 1);
    sub_541CA0(dword_7CF680);
    sub_542540(sub_4099E0, 0);
    sub_542680(0.5);
    return sub_542650(dword_7CF6EC);
  }
  return result;
}
