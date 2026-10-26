void __thiscall sub_415E00(float *this)
{
  int v2; // eax
  int v3; // edi
  float *v4; // eax
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st5
  float v10; // [esp+8h] [ebp-24h] BYREF
  float v11; // [esp+Ch] [ebp-20h]
  float v12; // [esp+10h] [ebp-1Ch]
  float v13; // [esp+14h] [ebp-18h]
  float v14; // [esp+18h] [ebp-14h]
  float v15; // [esp+1Ch] [ebp-10h]
  float v16; // [esp+28h] [ebp-4h]

  v2 = *((_DWORD *)this + 8);
  this[7] = 0.0;
  switch ( v2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( v2 )
      {
        switch ( v2 )
        {
          case 1:
            v3 = *(_DWORD *)(*((_DWORD *)this + 9) + 212);
            break;
          case 2:
            v3 = *(_DWORD *)(*((_DWORD *)this + 9) + 212);
            break;
          case 3:
            v3 = *(_DWORD *)(*((_DWORD *)this + 9) + 212);
            break;
          case 4:
            v3 = *(_DWORD *)(*((_DWORD *)this + 9) + 212);
            break;
          case 5:
            v3 = *(_DWORD *)(*((_DWORD *)this + 9) + 212);
            break;
          default:
            v3 = 0;
            break;
        }
      }
      else
      {
        v3 = *(_DWORD *)(*((_DWORD *)this + 9) + 212);
      }
      if ( v3 )
        goto LABEL_16;
      break;
    case 6:
      v4 = (float *)*((_DWORD *)this + 9);
      this[4] = v4[4380];
      this[5] = v4[4381];
      this[6] = v4[4382];
      this[7] = v4[4806];
      break;
    case 7:
      v3 = *((_DWORD *)this + 9);
      if ( v3 )
      {
        if ( (*(_BYTE *)(v3 + 60) & 0x10) == 0x10 )
        {
LABEL_16:
          sub_59E0C0(this + 4, this + 5, this + 6);
          this[7] = sqrt(sub_5079C0(v3));
        }
        else
        {
          sub_507620(&v10);
          v16 = v12 + v15;
          v5 = v11 + v14;
          v13 = (v10 + v13) * 0.5;
          this[4] = v13;
          v14 = v5 * 0.5;
          v6 = v16;
          this[5] = v14;
          v15 = v6 * 0.5;
          v7 = v10;
          this[6] = v15;
          v8 = v11 - this[5];
          v9 = v12 - this[6];
          this[7] = sqrt(v9 * v9 + v8 * v8 + (v7 - this[4]) * (v7 - this[4]));
        }
      }
      break;
    default:
      return;
  }
}
