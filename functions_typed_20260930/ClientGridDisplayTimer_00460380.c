void __thiscall sub_460380(int this)
{
  double v2; // st7
  int v3; // edi
  _BYTE v4[32]; // [esp+4h] [ebp-80h] BYREF
  _BYTE v5[96]; // [esp+24h] [ebp-60h] BYREF

  if ( *(_DWORD *)(this + 16324) == 3 )
  {
    v2 = *(float *)(this + 28) - dbl_8AFE98;
    *(float *)(this + 28) = v2;
    if ( v2 < 0.0 )
    {
      FAILWRONGDESCRIPTION(v4);
      if ( (unsigned __int8)UniqueID(v4) )
      {
        v3 = dword_8AC48C;
        SceneDataParser(v5);
        if ( *(_BYTE *)(this + 32) )
        {
          SessionConfigWriteback(v4);
          AIW(0);
          SystemOSAPICall_0dc0(&unk_7CE24D);
          if ( !byte_7CE254 )
            sub_4A0030(&unk_7CE24C);
          LookupDispatch(aMpclientgrid, -1);
          *(_BYTE *)(this + 32) = 0;
        }
        else if ( v3 != dword_8AC48C )
        {
          *(_BYTE *)(this + 32) = 1;
        }
        *(_DWORD *)(this + 28) = 1089470464;
      }
      EmptyStub_0170(v4);
    }
  }
}

