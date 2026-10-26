void __thiscall sub_40ED10(float *this)
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

  v2 = *((_DWORD *)this + 7);
  this[6] = 0.0;
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
            v3 = *(_DWORD *)(*((_DWORD *)this + 8) + 208);
            break;
          case 2:
            v3 = *(_DWORD *)(*((_DWORD *)this + 8) + 208);
            break;
          case 3:
            v3 = *(_DWORD *)(*((_DWORD *)this + 8) + 208);
            break;
          case 4:
            v3 = *(_DWORD *)(*((_DWORD *)this + 8) + 208);
            break;
          case 5:
            v3 = *(_DWORD *)(*((_DWORD *)this + 8) + 208);
            break;
          default:
            v3 = 0;
            break;
        }
      }
      else
      {
        v3 = *(_DWORD *)(*((_DWORD *)this + 8) + 208);
      }
      if ( v3 )
        goto LABEL_16;
      break;
    case 6:
      v4 = (float *)*((_DWORD *)this + 8);
      this[3] = v4[3381];
      this[4] = v4[3382];
      this[5] = v4[3383];
      this[6] = v4[3804];
      break;
    case 7:
      v3 = *((_DWORD *)this + 8);
      if ( v3 )
      {
        if ( (*(_BYTE *)(v3 + 60) & 0x10) == 0x10 )
        {
LABEL_16:
          sub_54B420(this + 3, this + 4, this + 5);
          this[6] = sqrt(sub_4DD8F0(v3));
        }
        else
        {
          sub_4DD550(&v10);
          v16 = v12 + v15;
          v5 = v11 + v14;
          v13 = (v10 + v13) * 0.5;
          this[3] = v13;
          v14 = v5 * 0.5;
          v6 = v16;
          this[4] = v14;
          v15 = v6 * 0.5;
          v7 = v10;
          this[5] = v15;
          v8 = v11 - this[4];
          v9 = v12 - this[5];
          this[6] = sqrt(v9 * v9 + v8 * v8 + (v7 - this[3]) * (v7 - this[3]));
        }
      }
      break;
    default:
      return;
  }
}
