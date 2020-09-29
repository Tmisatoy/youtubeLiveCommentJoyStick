const request = require("request");
require("dotenv").config();

const key = process.env.YOUTUBE_API_KEY;
const videoId = process.env.VIDEO_ID;

const getVideosList = (key, videoId) => {
  const URL = "https://www.googleapis.com/youtube/v3/videos";
  const Part = "liveStreamingDetails";

  console.log(key);
  console.log(videoId);

  request.get(
    {
      uri: URL,
      headers: { "Content-type": "application/json" },
      qs: {
        id: videoId,
        part: Part,
        key: key,
      },
      json: true,
    },
    function (err, req, data) {
      return data;
    }
  );
};

const getLiveChatMessages = (key, liveChatId) => {
  const URL = "https://www.googleapis.com/youtube/v3/liveChat/messages";
  const part = "id,snippet,authorDetails";
  const pageToken = process.env.PAGE_TOKEN;

  request.get(
    {
      uri: URL,
      headers: { "Content-type": "application/json" },
      qs: {
        liveChatId: liveChatId,
        part: part,
        key: key,
        pageToken: pageToken,
      },
      json: true,
    },
    function (err, req, data) {
      console.log(data);
    }
  );
};

const videosList = getVideosList(key, videoId);
console.log(videosList);
// const chatId = process.env.LIVE_CHAT_ID;
// const liveChatMessages = getLiveChatMessages(key, chatId);
// console.log(liveChatMessages);
// console.log(liveChatMessages.toJson);
