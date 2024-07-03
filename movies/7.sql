SELECT title FROM movies WHERE year = 2010 ORDER BY (SELECT rating FROM ratings WHERE movie_id = id) DESC;
