char __thiscall sub_458810(_DWORD *this, _DWORD *a2, int a3)
{
  char result; // al
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  void *v9; // eax
  int v10; // eax
  void *v11; // edi
  char String[384]; // [esp+Ch] [ebp-498h] BYREF
  int v13; // [esp+18Ch] [ebp-318h]
  char v14; // [esp+190h] [ebp-314h]
  int v15; // [esp+198h] [ebp-30Ch]
  int v16; // [esp+19Ch] [ebp-308h]
  int v17; // [esp+1A0h] [ebp-304h]
  char Buffer[384]; // [esp+1A4h] [ebp-300h] BYREF
  char String1[381]; // [esp+324h] [ebp-180h] BYREF
  __int16 v20; // [esp+4A1h] [ebp-3h]
  char v21; // [esp+4A3h] [ebp-1h]

  result = 0;
  if ( *a2 )
  {
    memset(Buffer, 0, sizeof(Buffer));
    String1[0] = byte_629120;
    memset(&String1[1], 0, 0x17Cu);
    v20 = 0;
    v13 = 0;
    v17 = 0;
    v15 = 0;
    v16 = 0;
    v14 = 1;
    v21 = 0;
    sub_4587E0(this);
    if ( a3 )
      sub_578600(a3);
    while ( sub_57A490(Buffer, 383) )
    {
      v5 = sub_577B60(String);
      if ( v5 )
      {
        if ( v5 == 2 || v5 == 4 )
          return 1;
      }
      else
      {
        if ( sub_577ED0(String, aType_0, String1, 0) )
        {
          if ( _strcmpi(String1, aLocal_0) )
          {
            if ( _strcmpi(String1, aSwingman) )
              this[2] = 2;
            else
              this[2] = 1;
          }
          else
          {
            this[2] = 0;
          }
        }
        if ( sub_577ED0(String, aGroup_0, String1, 0) )
          sub_578600(String1);
        sub_578220(aPosition_0, (int)(this + 5), (int)(this + 6), (int)(this + 7), 0, 0, 0, 0, 0);
        if ( sub_578220(aOrientation, (int)(this + 8), (int)(this + 9), (int)(this + 10), 0, 0, 0, 0, 0) )
        {
          v6 = this[9];
          this[26] = this[8];
          v7 = this[10];
          this[27] = v6;
          this[28] = v7;
        }
        if ( sub_578220(off_5FFA3C, (int)(this + 14), (int)(this + 15), 0, 0, 0, 0, 0, 0) )
        {
          v8 = this[15];
          this[16] = this[14];
          this[17] = v8;
        }
        sub_578220(aClipplanes_0, (int)(this + 18), (int)(this + 19), 0, 0, 0, 0, 0, 0);
        sub_578220(aLodmultiplier, (int)(this + 20), 0, 0, 0, 0, 0, 0, 0);
        sub_578220(aMipmapbias, (int)(this + 21), 0, 0, 0, 0, 0, 0, 0);
        sub_578220(aActivationloca, (int)(this + 22), (int)(this + 23), (int)(this + 24), 0, 0, 0, 0, 0);
        sub_578220(aActivationradi, (int)(this + 25), 0, 0, 0, 0, 0, 0, 0);
        sub_578220(aTrackingrate, (int)(this + 34), 0, 0, 0, 0, 0, 0, 0);
        sub_578110(aFlags1, (int)(this + 35), 0, 0, 0);
        sub_578220(aMovementrate, (int)(this + 31), 0, 0, 0, 0, 0, 0, 0);
        sub_578220(aSwingmanradius, (int)(this + 36), 0, 0, 0, 0, 0, 0, 0);
        if ( sub_577E50(String, aSpecial1_0, (int)String1) )
          sub_578600(String1);
        if ( sub_577E50(String, aSpecial2_0, (int)String1) )
          sub_578600(String1);
        if ( !_strcmpi(Buffer, aSplinepath) )
        {
          if ( !this[30] )
          {
            v9 = operator new(4u);
            if ( v9 )
              v10 = sub_45A520(v9);
            else
              v10 = 0;
            this[30] = v10;
          }
          if ( !(unsigned __int8)sub_45A570(a2) )
          {
            v11 = (void *)this[30];
            if ( v11 )
            {
              sub_45A550(this[30]);
              sub_5BE8AE(v11);
            }
            this[30] = 0;
          }
        }
      }
    }
    return 1;
  }
  return result;
}
