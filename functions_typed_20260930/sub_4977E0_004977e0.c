int __thiscall sub_4977E0(_DWORD *this, int a2, int a3)
{
  int result; // eax

  if ( a3 != -1 )
  {
    this[1375] = a2;
    sub_496E90((int)this, 1);
    result = sub_496E90((int)this, 1);
    switch ( a3 )
    {
      case 0:
        this[1374] = 0;
        this[55] = 1008981770;
        break;
      case 1:
        this[1374] = 1;
        this[55] = 1008981770;
        break;
      case 2:
        this[1374] = 2;
        this[55] = 1008981770;
        break;
      case 3:
        this[1374] = 3;
        goto LABEL_7;
      case 4:
LABEL_7:
        this[55] = 1008981770;
        break;
      default:
        return result;
    }
  }
  return result;
}

