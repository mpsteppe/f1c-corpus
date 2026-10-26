int __thiscall sub_658835(int this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // edx
  int v11; // edx

  sub_64FBCE((float *)this, (float *)a2, 0, 1);
  v3 = *(_DWORD *)(this + 4);
  *(_DWORD *)this = &off_737514;
  switch ( v3 )
  {
    case 827611204:
      *(_DWORD *)(this + 136) = 8;
      *(_DWORD *)(this + 144) = sub_67E31F;
      *(_DWORD *)(this + 140) = sub_67E01A;
      break;
    case 844388420:
      *(_DWORD *)(this + 136) = 16;
      *(_DWORD *)(this + 144) = sub_67EA92;
      *(_DWORD *)(this + 140) = sub_67EA46;
      break;
    case 861165636:
      *(_DWORD *)(this + 136) = 16;
      *(_DWORD *)(this + 144) = sub_67E443;
      *(_DWORD *)(this + 140) = sub_67E15C;
      break;
    case 877942852:
      *(_DWORD *)(this + 136) = 16;
      *(_DWORD *)(this + 144) = sub_67EACB;
      *(_DWORD *)(this + 140) = sub_67EA6C;
      break;
    case 894720068:
      *(_DWORD *)(this + 136) = 16;
      *(_DWORD *)(this + 144) = sub_67E572;
      *(_DWORD *)(this + 140) = sub_67E1E1;
      break;
  }
  qmemcpy((void *)(this + 148), (const void *)(a2 + 16), 0x18u);
  *(_DWORD *)(this + 172) = *(_DWORD *)(this + 148) & 0xFFFFFFFC;
  *(_DWORD *)(this + 176) = *(_DWORD *)(this + 152) & 0xFFFFFFFC;
  *(_DWORD *)(this + 188) = *(_DWORD *)(this + 164);
  v4 = *(_DWORD *)(this + 72);
  v5 = *(_DWORD *)(this + 60);
  *(_DWORD *)(this + 180) = (*(_DWORD *)(this + 156) + 3) & 0xFFFFFFFC;
  v6 = *(_DWORD *)(this + 160);
  v7 = *(_DWORD *)(this + 64);
  *(_DWORD *)(this + 232) = -1;
  *(_DWORD *)(this + 236) = -1;
  *(_DWORD *)(this + 184) = (v6 + 3) & 0xFFFFFFFC;
  *(_DWORD *)(this + 192) = *(_DWORD *)(this + 168);
  *(_DWORD *)(this + 212) = *(_DWORD *)(this + 76);
  v8 = (*(_DWORD *)(this + 68) + 3) & 0xFFFFFFFC;
  v5 &= 0xFFFFFFFC;
  *(_DWORD *)(this + 204) = v8;
  v9 = (v4 + 3) & 0xFFFFFFFC;
  v7 &= 0xFFFFFFFC;
  v10 = *(_DWORD *)(this + 80);
  *(_DWORD *)(this + 208) = v9;
  *(_DWORD *)(this + 220) = (v8 - v5) >> 2;
  *(_DWORD *)(this + 216) = v10;
  v11 = v10 - *(_DWORD *)(this + 76);
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = 0;
  *(_DWORD *)(this + 248) = 0;
  *(_DWORD *)(this + 196) = v5;
  *(_DWORD *)(this + 200) = v7;
  *(_DWORD *)(this + 224) = (v9 - v7) >> 2;
  *(_DWORD *)(this + 228) = v11;
  *(_DWORD *)(this + 252) = *(_DWORD *)(a2 + 64);
  return this;
}
