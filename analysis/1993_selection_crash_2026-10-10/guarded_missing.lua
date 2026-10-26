oph={noPlayer=function() return false end}
function CreateFile(_afile)
 local probe = io.open(_afile, "r")
 if not probe then return end
 probe:close()

-- lets auto fix the bch files GAMEOPT_opponents vaule
   i, j = string.find(_afile, '.bch')
   if i then 
	 local lines = {}
	 local opponents = 0;
	 
     for line in io.lines(_afile) do 
       lines[#lines + 1] = line
	   
	  ii, ji = string.find(tostring(line), '%[OPPONENT')
      if ii then 
        opponents = opponents + 1	  
	  end
     end	 

	 
	 np = oph.noPlayer() -- this checks if player is ai or not
	 
	 file = io.open(_afile,"w")
	 
	 for k,v in pairs(lines) do
      ii, ji = string.find(tostring(v), 'GAMEOPT_opponents')
      if ii then 
	    if np then
		  file:write("GAMEOPT_opponents="..tostring(opponents+1) .."\n")
		else
		  file:write("GAMEOPT_opponents="..tostring(opponents) .."\n")
		end		
      else
	    file:write(tostring(v) .."\n")	  
	  end
     end	
     print("auto fixed the ",_afile)
	 file:close()
   end
   
   
end
CreateFile("%USERPROFILE%/AppData/Local/Temp/f1c-1993-lua-rlpqk85x/guarded_missing.bch")
