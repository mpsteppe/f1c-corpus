int __thiscall sub_5C1840(int *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int result; // eax
  _DWORD v18[16]; // [esp+8h] [ebp-40h] BYREF

  v2 = *this;
  v3 = this[4];
  v4 = this[8];
  v18[0] = v2;
  v5 = this[12];
  v18[1] = v3;
  v6 = this[1];
  v18[2] = v4;
  v7 = this[5];
  v18[3] = v5;
  v8 = this[9];
  v18[4] = v6;
  v9 = this[13];
  v18[5] = v7;
  v10 = this[2];
  v18[6] = v8;
  v11 = this[6];
  v18[7] = v9;
  v12 = this[10];
  v18[8] = v10;
  v13 = this[14];
  v18[9] = v11;
  v14 = this[3];
  v18[10] = v12;
  v15 = this[7];
  v18[11] = v13;
  v16 = this[11];
  v18[12] = v14;
  result = this[15];
  v18[13] = v15;
  v18[14] = v16;
  v18[15] = result;
  qmemcpy(this, v18, 0x40u);
  return result;
}
