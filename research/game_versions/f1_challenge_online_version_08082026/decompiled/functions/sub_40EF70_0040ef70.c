int __thiscall sub_40EF70(_DWORD *this, float *a2)
{
  float *v2; // ebx
  double v4; // st7
  int v5; // eax
  double v6; // st7
  int v7; // eax
  double v9[3]; // [esp+10h] [ebp-48h] BYREF
  double v10[3]; // [esp+28h] [ebp-30h] BYREF
  double v11[3]; // [esp+40h] [ebp-18h] BYREF

  v2 = a2;
  switch ( this[7] )
  {
    case 0:
    case 2:
    case 4:
      v4 = *a2;
      v5 = this[8];
      *(float *)(v5 + 36) = *a2;
      *(float *)(v5 + 32) = v4 + 100.0;
      a2 = (float *)(this[8] + 212);
      break;
    case 1:
    case 3:
    case 5:
      v6 = *a2;
      v7 = this[8];
      *(float *)(v7 + 36) = *a2;
      *(float *)(v7 + 32) = v6 + 100.0;
      a2 = (float *)(this[8] + 212);
      break;
    default:
      break;
  }
  this[3] = *((_DWORD *)v2 + 1);
  this[4] = *((_DWORD *)v2 + 2);
  this[5] = *((_DWORD *)v2 + 3);
  sub_54B4D0(*((_DWORD *)v2 + 1), *((_DWORD *)v2 + 2), *((_DWORD *)v2 + 3), v2[4], v2[5], v2[6]);
  v9[0] = v2[1];
  v9[1] = v2[2];
  v9[2] = v2[3];
  qmemcpy(a2 + 1, v9, 0x18u);
  v10[0] = v2[4];
  v10[1] = v2[5];
  v10[2] = v2[6];
  sub_5691D0(v10);
  v9[0] = v2[7];
  v9[1] = v2[8];
  v9[2] = v2[9];
  qmemcpy(a2 + 25, v9, 0x18u);
  v11[0] = v2[10];
  v11[1] = v2[11];
  v11[2] = v2[12];
  sub_569280(v11);
  return sub_40F0D0(this);
}
