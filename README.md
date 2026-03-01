ketu is a small game/graphical project I did for my studies in Hive Helsinki. The project's official 
name of the project is so_long and it utilizes the MLX42 graphical library.

To play the game:
1)Clone the repo
2)make
3)Run ./so_long <maps/<map_file>> (I usually do ./so_long maps/second.ber)
4)Move around the map using WASD, gather all the apples, make your escape through the foxhole.


The gist of the project was figuring ways to do the following:
1)Read from a file(that would be the map file), and validate it:
  It needs to be rectangular, enclosed by walls, have collectibles and all of them being reachable
  by the player, only one player, and one exit, which also has to be reachable.
2)Learn how to use MLX42, how the loop works for games.
3)Manage memory efficiently in your own code, even though the MLX42 library leaks.
4)Avoid crashes.

It was a really fun and challenging project for the time, but the result kind of makes up 
for the frustrations of figuring things out. Personally I thought how cool it is 
to be able to make something like that, the possibilities and limits being mostly your 
imagination. I am sure there are plenty of other limitations, but it felt cool to think that
"Ah, this could be my "party trick" or custom birthday gift to someone I love etc". I don't know,
that was the thought that came to mind at the time. 
