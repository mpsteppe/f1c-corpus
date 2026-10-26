void __thiscall sub_467E40(_DWORD *this, int a2, char a3, char a4)
{
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // edx
  char *v8; // eax
  char *v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // esi
  char *v13; // eax
  char *v14; // ecx
  char *v15; // [esp+Ch] [ebp-90h]
  int v16; // [esp+14h] [ebp-88h] BYREF
  char Buffer[16]; // [esp+18h] [ebp-84h] BYREF
  _BYTE v18[4]; // [esp+28h] [ebp-74h] BYREF
  _BYTE v19[112]; // [esp+2Ch] [ebp-70h] BYREF

  if ( this[23] )
  {
    v5 = this[73] + this[72];
    v6 = 0;
    if ( v5 <= 0 )
    {
LABEL_8:
      this[v5 + 24] = a2;
      if ( a3 )
        ++this[72];
      else
        ++this[73];
      sub_462BC0(v18);
      if ( !a4 && (unsigned __int8)sub_463CD0(dword_764D70, a2, v18, &v16) )
      {
        v15 = (char *)operator new(0x80u);
        *v15 = 0;
        sub_578560(v19);
        sub_578560(aVoted);
        v8 = (char *)&off_600828;
        if ( !a3 )
          v8 = aNo;
        sub_578560(v8);
        sub_578560(aTo);
        if ( this[23] == 1 )
        {
          v9 = aAdvanceToNextS;
        }
        else if ( this[23] == 2 )
        {
          v9 = aAdvanceToNextE;
        }
        else
        {
          v9 = aNoIssue;
        }
        sub_578560(v9);
        sub_578560(word_5FC804);
        v10 = this[72];
        v11 = this[21];
        if ( v10 >= v11 )
        {
          sub_578560(aVotePassed);
        }
        else
        {
          v12 = v11 - v10;
          Buffer[0] = 0;
          sprintf(Buffer, "%d", v12);
          sub_578560(aIssueNeeds);
          sub_578560(Buffer);
          sub_578560(aVote);
          v13 = aS_1;
          if ( v12 <= 1 )
            v13 = &byte_629120;
          sub_578560(v13);
          sub_578560(aToPass);
        }
        v14 = v15;
        if ( !v15 )
          v14 = &byte_629120;
        sub_468300(v14);
        if ( v15 )
          sub_5BE8AE(v15);
      }
      nullsub_6(v18);
    }
    else
    {
      v7 = this + 24;
      while ( *v7 != a2 )
      {
        ++v6;
        ++v7;
        if ( v6 >= v5 )
          goto LABEL_8;
      }
      if ( !a4 )
        sub_468300(aVoteIgnoredYou);
    }
  }
  else if ( !a4 )
  {
    sub_468300(aVoteIgnoredThe);
  }
}
