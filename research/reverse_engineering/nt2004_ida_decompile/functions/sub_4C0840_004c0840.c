int __thiscall sub_4C0840(_DWORD *this)
{
  int v2; // esi
  double v3; // st7
  int result; // eax
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]

  v2 = 13;
  v7 = (*(float *)(*this + 18796) - *(float *)(*this + 18792)) / *(float *)(*this + 18796);
  v5 = *(float *)(*this + 18796);
  v3 = sub_4C2BB0() / v5;
  v6 = v3;
  if ( v3 >= 0.0 )
  {
    if ( v6 > (double)v7 )
      v6 = v7;
  }
  else
  {
    v6 = 0.0;
  }
  switch ( this[40] )
  {
    case 0:
      if ( v6 > 0.0099999998 )
      {
        if ( v6 > 0.25 )
        {
          if ( v6 > 0.5 )
          {
            if ( v6 > 0.75 )
              result = sub_4C0A80(4);
            else
              result = sub_4C0A80(3);
          }
          else
          {
            result = sub_4C0A80(2);
          }
        }
        else
        {
          result = sub_4C0A80(1);
        }
      }
      else
      {
        result = sub_4C0A80(0);
      }
      break;
    case 1:
      if ( v6 > 0.0099999998 )
      {
        if ( v6 > 0.5 )
          result = sub_4C0A80(7);
        else
          result = sub_4C0A80(6);
      }
      else
      {
        result = sub_4C0A80(5);
      }
      break;
    case 2:
      if ( v6 > 0.0099999998 )
      {
        if ( v6 > 0.5 )
          result = sub_4C0A80(10);
        else
          result = sub_4C0A80(9);
      }
      else
      {
        result = sub_4C0A80(8);
      }
      break;
    case 3:
      if ( v6 > 0.0099999998 )
      {
        v2 = 12;
        if ( v6 > 0.5 )
          v2 = 13;
        goto LABEL_29;
      }
      result = sub_4C0A80(11);
      break;
    default:
LABEL_29:
      result = sub_4C0A80(v2);
      break;
  }
  return result;
}
