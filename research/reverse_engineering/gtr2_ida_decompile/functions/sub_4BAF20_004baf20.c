int __thiscall sub_4BAF20(_DWORD *this, int a2)
{
  this[189] = a2;
  switch ( a2 )
  {
    case 1:
      this[188] = 10;
      goto LABEL_7;
    case 2:
      this[187] = 10;
      this[188] = 21;
      break;
    case 3:
      this[187] = 21;
      this[188] = 34;
      break;
    case 4:
      this[187] = 34;
      this[188] = dword_B73AA4;
      break;
    default:
      this[188] = 9;
      this[189] = 1;
LABEL_7:
      this[187] = 0;
      break;
  }
  sub_4BAD70();
  this[139] = 0;
  sub_4D0B20(this);
  return sub_4CE500(this);
}
