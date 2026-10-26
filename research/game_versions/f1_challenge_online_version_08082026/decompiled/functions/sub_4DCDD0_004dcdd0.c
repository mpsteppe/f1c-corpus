int __thiscall sub_4DCDD0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // edx

  this[4] = a4;
  switch ( a5 )
  {
    case 0:
      this[2] = a2;
      this[3] = a3;
      return sub_4DCA80(this);
    case 1:
      this[2] = a2 - this[5];
      this[3] = a3;
      return sub_4DCA80(this);
    case 2:
      this[2] = a2 - this[5] / 2;
      this[3] = a3;
      return sub_4DCA80(this);
    case 3:
      this[2] = a2;
      this[3] = a3 - this[6];
      return sub_4DCA80(this);
    case 4:
      v6 = this[5];
      goto LABEL_8;
    case 5:
      v6 = this[5] / 2;
LABEL_8:
      this[2] = a2 - v6;
      this[3] = a3 - this[6];
      return sub_4DCA80(this);
    case 6:
      v7 = a2;
      goto LABEL_12;
    case 7:
      this[2] = a2 - this[5];
      goto LABEL_13;
    case 8:
      v7 = a2 - this[5] / 2;
LABEL_12:
      this[2] = v7;
LABEL_13:
      this[3] = a3 - this[6] / 2;
      break;
    default:
      return sub_4DCA80(this);
  }
  return sub_4DCA80(this);
}
