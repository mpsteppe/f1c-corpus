char __thiscall sub_537570(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int i; // edx
  _DWORD v9[3]; // [esp+0h] [ebp-198h] BYREF
  _DWORD v10[3]; // [esp+Ch] [ebp-18Ch] BYREF
  _DWORD v11[3]; // [esp+18h] [ebp-180h] BYREF
  _DWORD v12[3]; // [esp+24h] [ebp-174h] BYREF
  _DWORD v13[3]; // [esp+30h] [ebp-168h] BYREF
  _DWORD v14[3]; // [esp+3Ch] [ebp-15Ch] BYREF
  _DWORD v15[3]; // [esp+48h] [ebp-150h] BYREF
  _DWORD v16[3]; // [esp+54h] [ebp-144h] BYREF
  _DWORD v17[3]; // [esp+60h] [ebp-138h] BYREF
  _DWORD v18[3]; // [esp+6Ch] [ebp-12Ch] BYREF
  _DWORD v19[3]; // [esp+78h] [ebp-120h] BYREF
  char String[12]; // [esp+84h] [ebp-114h] BYREF
  char v21; // [esp+90h] [ebp-108h] BYREF

  if ( a2[1] )
  {
    while ( (*(int (__thiscall **)(_DWORD *, char *, int))(*a2 + 36))(a2, byte_903710, 256) )
    {
      v3 = sub_612EB0(&unk_9034F8);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( !v4 || v4 == 3 )
          break;
      }
      else if ( strstr(byte_903710, "[PLAYERTRACKSTAT]") )
      {
        sub_5352C0(this, a2);
      }
      else
      {
        sub_6133A0("ABORTEDSEASONS", this + 16, 0, 0, 0);
        sub_6133A0("TOTALLAPS", this + 28, 0, 0, 0);
        sub_6133A0("TOTALRACES", this + 40, 0, 0, 0);
        sub_6133A0("TOTALRACESWITHAI", this + 52, 0, 0, 0);
        sub_6133A0("TOTALPOINTSSCORED", this + 64, 0, 0, 0);
        sub_6133A0("TOTALCHAMPIONSHIPS", this + 76, 0, 0, 0);
        sub_6133A0("TOTALWINS", this + 88, 0, 0, 0);
        sub_6133A0("TOTALPOLES", this + 100, 0, 0, 0);
        sub_6133A0("TOTALLAPRECORDS", this + 112, 0, 0, 0);
        sub_6133A0("CATEGORYPOINTSSCORED", this + 148, 0, 0, 0);
        sub_6133A0("CATEGORYCHAMPIONSHIPS", this + 136, 0, 0, 0);
        sub_6133A0("CATEGORYWINS", this + 124, 0, 0, 0);
        *(_DWORD *)String = 0;
        v19[2] = &v21;
        v19[1] = "AVGSTARTPOSITION";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 160) = atof(String);
        v19[0] = 0;
        v18[2] = String;
        v18[1] = "AVGFINISHPOSITION";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 172) = atof((const char *)v19);
        v18[0] = 0;
        v17[2] = v19;
        v17[1] = "AVGRACEDISTANCE";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 184) = atof((const char *)v18);
        v17[0] = 0;
        v16[2] = v18;
        v16[1] = "AVGOPPONENTSTRENGTH";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 196) = atof((const char *)v17);
        sub_6133A0("PROTOTALLAPS", this + 24, 0, 0, 0);
        sub_6133A0("PROTOTALRACES", this + 36, 0, 0, 0);
        sub_6133A0("PROTOTALRACESWITHAI", this + 48, 0, 0, 0);
        sub_6133A0("PROTOTALPOINTSSCORED", this + 60, 0, 0, 0);
        sub_6133A0("PROTOTALCHAMPIONSHIPS", this + 72, 0, 0, 0);
        sub_6133A0("PROTOTALWINS", this + 84, 0, 0, 0);
        sub_6133A0("PROTOTALPOLES", this + 96, 0, 0, 0);
        sub_6133A0("PROTOTALLAPRECORDS", this + 108, 0, 0, 0);
        sub_6133A0("PROCATEGORYPOINTSSCORED", this + 144, 0, 0, 0);
        sub_6133A0("PROCATEGORYCHAMPIONSHIPS", this + 132, 0, 0, 0);
        sub_6133A0("PROCATEGORYWINS", this + 120, 0, 0, 0);
        v16[0] = 0;
        v15[2] = v17;
        v15[1] = "PROAVGSTARTPOSITION";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 156) = atof((const char *)v16);
        v15[0] = 0;
        v14[2] = v16;
        v14[1] = "PROAVGFINISHPOSITION";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 168) = atof((const char *)v15);
        v14[0] = 0;
        v13[2] = v15;
        v13[1] = "PROAVGRACEDISTANCE";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 180) = atof((const char *)v14);
        v13[0] = 0;
        v12[2] = v14;
        v12[1] = "PROAVGOPPONENTSTRENGTH";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 192) = atof((const char *)v13);
        sub_6133A0("ARCADETOTALLAPS", this + 20, 0, 0, 0);
        sub_6133A0("ARCADETOTALRACES", this + 32, 0, 0, 0);
        sub_6133A0("ARCADETOTALRACESWITHAI", this + 44, 0, 0, 0);
        sub_6133A0("ARCADETOTALPOINTSSCORED", this + 56, 0, 0, 0);
        sub_6133A0("ARCADETOTALCHAMPIONSHIPS", this + 68, 0, 0, 0);
        sub_6133A0("ARCADETOTALWINS", this + 80, 0, 0, 0);
        sub_6133A0("ARCADETOTALPOLES", this + 92, 0, 0, 0);
        sub_6133A0("ARCADETOTALLAPRECORDS", this + 104, 0, 0, 0);
        sub_6133A0("ARCADECATEGORYPOINTSSCORED", this + 140, 0, 0, 0);
        sub_6133A0("ARCADECATEGORYCHAMPIONSHIPS", this + 128, 0, 0, 0);
        sub_6133A0("ARCADECATEGORYWINS", this + 116, 0, 0, 0);
        v12[0] = 0;
        v11[2] = v13;
        v11[1] = "ARCADEAVGSTARTPOSITION";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 152) = atof((const char *)v12);
        v11[0] = 0;
        v10[2] = v12;
        v10[1] = "ARCADEAVGFINISHPOSITION";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 164) = atof((const char *)v11);
        v10[0] = 0;
        v9[2] = v11;
        v9[1] = "ARCADEAVGRACEDISTANCE";
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 176) = atof((const char *)v10);
        v9[0] = 0;
        if ( sub_6137E0(&unk_9034F8) )
          *(float *)(this + 188) = atof((const char *)v9);
      }
    }
  }
  v5 = sub_5354C0(*(_DWORD *)this);
  v6 = v5;
  *(_DWORD *)this = v5;
  if ( v5 )
  {
    for ( i = *(_DWORD *)(v5 + 4); i; i = *(_DWORD *)(i + 4) )
      v6 = i;
  }
  *(_DWORD *)(this + 8) = v5;
  *(_DWORD *)(this + 4) = v6;
  return 0;
}
